//
// Created by hilla on 2024-03-15.
//
#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCV_Setting.h"


int main(){
    cv::Mat origin, src, src_gray, dst, dst_filtered, dst_threshold, dst_morph;

    // |************************* Read, Resize, Convert to GrayScale Sourc Image *************************|
    src = cv::imread("../Image/Lab_GrayScale_TestImage.jpg", 1);

    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    // |************************* Tresholding and Morpholgy *************************|
    dst_morph = Threshold_Morphology(src_gray, dst_morph, 111, 4, 3);

    // |************************* Filter *************************|
    dst_filtered = filter(dst_morph, MEDIAN, 9);

    // |************************* Ploting Histogram *************************|
    // plotHist(dst_filtered,"Histogram", 500, 500);

    // |************************* Draw Contours on the original image *************************|
    contour(src, dst_filtered);

    imshow("", resizing(dst_filtered, 1024, 1024));
    imshow("Contours on Original", resizing(src, 1024, 1024));

    waitKey(0);
}



