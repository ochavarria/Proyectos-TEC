

import numpy
import math
import cv2
from time import time
from timeit import timeit


class class_eigen_faces_algorithm:
    def __init__(self, database_system_path):
        """
        Class constructor 
        @param Images path 
        @return  
        """
        self.database_system_path = database_system_path
        self.labels = []
        self.matrix = []
        self.average_face = []
        self.average_vector = []
        self.covariance_matrix = []
        self.eigen_vectors = []
        self.eigen_values = []
        self.generated_space = []
        self.proyected_faces = []

    def load_images(self):
        """
        Method that load the images 
        @param 
        @return  boolean
        """
        try:
            for i in range(1, 42):
                for j in range(1, 10):
                    _label_ = "Subject: " + str(42 - i)
                    _url_ = self.database_system_path
                    _url_ = _url_ + str(i)
                    _url_ = _url_ + '/'
                    _url_ = _url_ + str(j)
                    _url_ = _url_ + '.pgm'
                    self.labels.append(_label_)
                    _image_ = cv2.imread(_url_, 0)
                    _vector_ = _image_.flatten()
                    if i == 1 and j == 1:
                        self.matrix = [_vector_]
                    else:
                        self.matrix = numpy.append(
                            self.matrix, [_vector_], axis=0)

            #self.matrix=numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
            self.matrix = self.matrix.T
            return True
        except ImportError:
            return False

    def handmade_covariance(self):
        """
        Method that create's the covariance
        @param 
        @return  numpy.ndarray covariance_matrix
        """
        _sample_matrix_ = self.matrix
        _sum_sample_ = numpy.sum(self.matrix, axis=1)
        _mean_sample_ = _sum_sample_ / len(self.matrix.T)
        self.average_vector = _mean_sample_
        self.average_face = _sample_matrix_ - _mean_sample_[:, numpy.newaxis]

        _transpose_average_matrix = self.average_face.T
        _inner_product_matrix_ = numpy.dot(
            _transpose_average_matrix, self.average_face)
        self.covariance_matrix = _inner_product_matrix_
        #print(self.covariance_matrix )
        return self.covariance_matrix

    def eigen_vector_matrix(self):
        """
        Method that create's the eigen vectors 
        @param 
        @return  numpy.ndarray eigen_vectors
        """
        [n, d] = self.matrix.shape
        self.eigen_values, self.eigen_vectors = numpy.linalg.eigh(
            self.covariance_matrix)
        self.eigen_vectors = numpy.dot(self.average_face, self.eigen_vectors)
        # print(self.eigen_vectors)
        return self.eigen_vectors

    def most_significant_vectors(self, percentage):
        """
        Method that takes out the most significant vectors 
        @param  float percentage
        @return  numpy.ndarray generated_space
        """

        if percentage > 1:
            return "ERROR"
        else:
            _transpose_eigen_vectors_ = self.eigen_vectors.T
            _chosen_eigen_vectors = percentage * len(
                _transpose_eigen_vectors_)
            _chosen_eigen_vectors = _chosen_eigen_vectors // 1

            _eigen_values_ = self.eigen_values.tolist()
            _current_eigen_vectors_ = _transpose_eigen_vectors_.tolist()

            _most_significant_eigen_vector_ = []
            _sorted_labels_ = []

            while len(_most_significant_eigen_vector_) < _chosen_eigen_vectors:
                _max_eigen_value_ = max(_eigen_values_)
                _vector_index_ = _eigen_values_.index(
                    _max_eigen_value_)
                _eigen_values_.remove(_max_eigen_value_)
                _sorted_labels_.append(self.labels[_vector_index_])
                self.labels.remove(self.labels[_vector_index_])
                _most_significant_eigen_vector_.append(
                    _current_eigen_vectors_[_vector_index_])
                _current_eigen_vectors_.remove(
                    _current_eigen_vectors_[_vector_index_])

            _most_significant_eigen_vector_ = numpy.asarray(
                _most_significant_eigen_vector_)
            self.labels = _sorted_labels_
            self.generated_space = _most_significant_eigen_vector_.T
            # print(self.generated_space)
            return self.generated_space

    def detection_faces(self):
        """
        Method that proyect the faces  
        @param  
        @return  numpy.ndarray proyected_faces
        """
        self.proyected_faces = numpy.dot(
            self.generated_space.T, self.average_face)
        # print(self.proyected_faces)
        return self.proyected_faces

    def proyected_image(self, _url_):
        """
        Method that load the face and detects it 
        @param  
        @return  String label
        """
        _new_image_ = cv2.imread(_url_, 0)
        _vector_image_ = _new_image_.flatten()
        _vector_image_ = _vector_image_ - self.average_vector
        _proyected_image_ = numpy.dot(
            self.generated_space.T, _vector_image_)
        _substraction_list_ = []
        for i in range(len(self.proyected_faces)):
            _substraction_list_.append(
                self.euclidean_distance(
                    _proyected_image_, self.proyected_faces.T[i]))
        _index_number_ = _substraction_list_.index(
            min(_substraction_list_))
        print("=================================================")
        print("\t\t" + self.labels[_index_number_])
        print("=================================================")
        return self.labels[_index_number_]

    def euclidean_distance(self, x, v):
        """
        Method that calculate the eucliden distance 
        @param  
        @return  float distance
        """
        return numpy.sqrt(numpy.sum((x - v)**2))


#start_time = time()


_test_ = class_eigen_faces_algorithm(
    'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
_test_.load_images()
_test_.handmade_covariance()
_test_.eigen_vector_matrix()
_test_.most_significant_vectors(0.9)
_test_.detection_faces()
"""_test_.proyected_image(
    'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/1.pgm')
_test_.euclidean_distance(numpy.array([1,2,3]), numpy.array([4,5,6]))

elapsed_time = time() - start_time
print("Elapsed time: %.10f seconds." % elapsed_time)"""
