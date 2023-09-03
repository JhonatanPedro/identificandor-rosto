// blibiotecas necesarias 
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

int main() {

	// iniciando o classificador
	CascadeClassifier faceCascade;
	
	// checando se o indentificador foi carregado
	if (!faceCascade.load("haarcascade-frontalface-default.xml")) {
		cerr << "Erro ao carregar o classificador de faces." << endl;
		return -1;
	}

	// iniciando a imagem
	Mat image = imread("rostos.jpg");

	// convertendo a imagem para cinza pois e necessario para podemos indentificar os rostos
	Mat imageCinza;
	cvtColor(image, imageCinza, COLOR_BGR2GRAY);

	// indentificando os rostos
	vector<Rect> faces;
	faceCascade.detectMultiScale(imageCinza, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	//desenhando os retangulos nos rostos
	for (size_t i = 0; i < faces.size(); ++i) {
		rectangle(image, faces[i], Scalar(0, 255, 0), 2);
	}

	// checando se a imagen foi carregada
	if (image.empty()) {
		cerr << "Erro ao carregar a imagen." << endl;
		return -1;
	}
	// mostrando a imagem
	imshow("My image", image);
	waitKey(0);

	return 0;
}