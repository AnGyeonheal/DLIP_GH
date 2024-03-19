//
// Created by hilla on 2024-03-15.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    cv::Mat src, dst;
    src = cv::imread("../Image/Lab_GrayScale_TestImage.jpg", 0);

    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    Laplacian(src, dst, ddepth, kernel_size, scale, delta);
    src.convertTo(src, CV_16S);
    cv::
    imshow("image", dst);

    waitKey(0);


}