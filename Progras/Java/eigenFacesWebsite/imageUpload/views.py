from django.shortcuts import render
from django.http import HttpResponse
from businessLogic import eigenFacesAlgorithm
import os
# Create your views here.


def home(request):
    """
        Method that load the page with the request 
        @param   Request request
        @return  View 
        """

    if request.method == 'POST':
        response = handle_uploaded_file(
            request.FILES['file'], str(request.FILES['file']))
        img = "imageUpload/img/s" + response.split(" ", 1)[1] + ".png"
        return render(request, 'index.html', {'response': response, 'imgpath': img})

    return render(request, 'index.html', {'response': 'Sujeto Identificado', 'imgpath': "imageUpload/img/default.jpg"})


def handle_uploaded_file(file, filename):
    """
        Method that upload a file 
        @param   File file , String filename 
        @return  String subjectname 
        """
    if not os.path.exists('upload/'):
        os.mkdir('upload/')

    with open('upload/' + filename, 'wb+') as destination:
        for chunk in file.chunks():
            destination.write(chunk)
    filepath = 'upload/' + filename
    return eigenFacesAlgorithm._test_.proyected_image(filepath)
