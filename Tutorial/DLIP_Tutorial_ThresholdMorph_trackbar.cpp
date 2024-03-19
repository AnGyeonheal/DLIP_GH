/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV : Threshold using Trackbar Demo
* Created: 2021-Spring
------------------------------------------------------*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

// Global variables for Threshold
int threshold_value = 0;
int threshold_type = 0;
int morphology_type = 0;

int const max_value = 255;
int const max_type = 8;
int const max_BINARY_value = 255;

// Global variables for Morphology
int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
int n = 3;
Mat element = getStructuringElement(element_shape, Size(n, n));

Mat src, src_gray, dst, dst_morph;


// Trackbar strings
String window_name = "Threshold & Morphology Demo";
String trackbar_type = "Thresh Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Invertd \n 8:OTSU";
String trackbar_value = "Thresh Value";
String trackbar_morph = "Morph Type 0: None \n 1: erode \n 2: dilate \n 3: close \n 4: open";

// Function headers
void Threshold_Demo(int, void*);
void Morphology_Demo(int, void*);
void saveSettingsToFile();

int main()
{
    // Load an image
    src = imread("../Image/localThresh1.jpg", IMREAD_COLOR);

    // Convert the image to Gray
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    // Create a window to display the results
    namedWindow(window_name, WINDOW_NORMAL);

    // Create trackbar to choose type of threshold
    createTrackbar(trackbar_type, window_name, &threshold_type, max_type, Threshold_Demo);
    createTrackbar(trackbar_value, window_name, &threshold_value, max_value, Threshold_Demo);
    createTrackbar(trackbar_morph, window_name, &morphology_type, max_type, Morphology_Demo);

    // Call the function to initialize
    Threshold_Demo(0, 0);
    Morphology_Demo(0, 0);

    // Wait until user finishes program
    while (true) {
        int c = waitKey(20);
        if (c == 27) // ESC 키를 누르면 종료
            break;
        if (c == 's' || c == 'S') // 's' 키를 누르면 설정 저장
            saveSettingsToFile();
    }
}

void Threshold_Demo(int, void*)	// default form of callback function for trackbar
{
    /*
    * 0: Binary
    * 1: Threshold Truncated
    * 2: Threshold to Zero
    * 3: Threshold to Zero Inverted
    * 8: Threshold OTSU
    */

    threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
    imshow(window_name, dst);
}

void Morphology_Demo(int, void*)  // default form of callback function for trackbar
{
    /*
    * 0: None
    * 1: Erode
    * 2: Dilate
    * 3: Close
    * 4: Open
    */

    switch (morphology_type) {
        case 0: dst.copyTo(dst_morph);	break;
        case 1: erode(dst, dst_morph, element); break;
        case 2: dilate(dst, dst_morph, element); break;
        case 3: morphologyEx(dst, dst_morph, MORPH_OPEN, element); break;
        case 4: morphologyEx(dst, dst_morph, MORPH_CLOSE, element); break;
    }
    imshow(window_name, dst_morph);
}

void saveSettingsToFile() {
    // 설정을 저장할 파일 열기
    ofstream file("settings.txt", ios::out | ios::app); // append 모드로 열기

    // 파일이 성공적으로 열렸는지 확인
    if (file.is_open()) {
        // 파일에 설정 정보 쓰기
        file << "File Name: " << "localThresh1.jpg" << "\n"; // 이미지 파일 이름
        file << "Threshold Type: " << threshold_type << "\n";
        file << "Morphology Type: " << morphology_type << "\n";
        file << "Threshold Value: " << threshold_value << "\n\n"; // 두 줄 개행으로 설정 구분

        // 파일 닫기
        file.close();
        cout << "Settings saved to settings.txt" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}
