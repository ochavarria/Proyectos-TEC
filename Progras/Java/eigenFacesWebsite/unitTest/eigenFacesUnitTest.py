'''
Created on 20 ago. 2017

@author: Byron
'''
import unittest
import numpy

from businessLogic.eigenFacesAlgorithm import class_eigen_faces_algorithm


class class_test_um(unittest.TestCase):
    """
    Class that initiate the program

    """

    def test_load_images(self):
        """
        Method that test the load image function  
        @param 
        @return  function test output 
        """
        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        print("____________________________________________________________")
        print("Test : load_images()")
        self.assertEqual(_test_object_.load_images(), True)
        print("____________________________________________________________")

        pass

    def test_handmade_covariance(self):
        """
        Method that test the handmade covariance function  
        @param 
        @return  function test output 
        """
        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        _expected_result_ = numpy.array([[3.,  0., -3.], [0.,  0.,  0.],
                                         [-3.,  0.,  3.]])
        _test_input_ = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
        _test_object_.matrix = _test_input_
        print("__________________________________________________________")
        print("Test : handmade_covariance()")
        self.assertTrue((_test_object_.handmade_covariance() ==
                         _expected_result_).all())
        print("Input for test:")
        print(_test_input_)
        print("Expected result:")
        print(_expected_result_)
        print("__________________________________________________________")

        pass

    def test_eigen_vector_matrix(self):
        """
        Method that test the vector matrix function  
        @param 
        @return  function test output 
        """
        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        _expected_result_ = numpy.array([[0., 0., 1.41421356], [0., 0., 1.41421356],
                                         [0., 0., 1.41421356]])
        _test_input_ = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
        _test_object_.matrix = _test_input_
        _test_object_.handmade_covariance()
        print("____________________________________________________")
        print("Test :eigen_vector_matrix()")
        self.assertTrue(numpy.allclose(_test_object_.eigen_vector_matrix(),
                                       _expected_result_))
        print("Input for test:")
        print(_test_input_)
        print("Expected result:")
        print(_expected_result_)
        print("__________________________________________________________")

        pass

    def test_most_significant_vectors(self):
        """
        Method that test the most significant vectors  function
        @param 
        @return  function test output 
        """
        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        _expected_result_ = numpy.array([[1.41421356, 0., 0.], [1.41421356, 0., 0.],
                                         [1.41421356, 0., 0.]])
        _test_input_ = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
        _test_object_.matrix = _test_input_
        _test_object_.labels = ["s1", "s2", "s3",
                                "s4", "s5", "s6", "s7", "s8", "s9"]
        _test_object_.handmade_covariance()
        _test_object_.eigen_vector_matrix()
        print("____________________________________________________")
        print("Test :most_significant_vectors()")
        self.assertTrue(numpy.allclose(_test_object_.most_significant_vectors(1),
                                       _expected_result_))
        print("Input for test:")
        print(_test_input_)
        print("Expected result:")
        print(_expected_result_)
        print("__________________________________________________________")
        pass

    def test_detection_faces(self):
        """
        Method that test the detection faces vectors  function
        @param 
        @return  function test output 
        """
        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        _expected_result_ = numpy.array([[-4.24264069, 0., 4.24264069], [0., 0., 0.],
                                         [0., 0., 0.]])
        _test_input_ = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
        _test_object_.matrix = _test_input_
        _test_object_.labels = ["s1", "s2", "s3",
                                "s4", "s5", "s6", "s7", "s8", "s9"]
        _test_object_.handmade_covariance()
        _test_object_.eigen_vector_matrix()
        _test_object_.most_significant_vectors(1)
        print("____________________________________________________")
        print("Test :detection_faces()")
        self.assertTrue(numpy.allclose(_test_object_.detection_faces(),
                                       _expected_result_))
        print("Input for test:")
        print(_test_input_)
        print("Expected result:")
        print(_expected_result_)
        print("__________________________________________________________")
        pass

    def test_euclidean_distance(self):
        """
        Method that test the euclidean distance function
        @param 
        @return  function test output 
        """

        _test_object_ = class_eigen_faces_algorithm(
            'C:/Users/freys/Desktop/SegundoSemestre2017/aseguramiento/input/s')
        _test_input_ = "Vector1: " + \
            str([1, 2, 3]) + "Vector1: " + str([4, 5, 6])
        _expected_result_ = 5.19615242271
        print("____________________________________________________")
        print("Test :euclidean_distance()")
        self.assertTrue(numpy.allclose(_test_object_.euclidean_distance(
            numpy.array([1, 2, 3]), numpy.array([4, 5, 6])), _expected_result_))
        print("Input for test:")
        print(_test_input_)
        print("Expected result:")
        print(_expected_result_)
        print("__________________________________________________________")
        pass


if __name__ == '__main__':
    unittest.main()
