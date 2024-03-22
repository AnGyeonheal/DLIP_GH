//
// Created by hilla on 2024-03-15.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
void plotHist(Mat src, string plotname, int width, int height);
void contour(Mat& src, Mat dst);

int main(){
    cv::Mat src, src_gray, dst, dst_filtered, dst_threshold, dst_morph;
    int element_shape = MORPH_RECT;
    int n = 3;
    Mat element = getStructuringElement(element_shape, Size(n, n));

    // 1. Source Image

    src = cv::imread("../Image/Lab_GrayScale_TestImage.jpg", 1);
    // cv::imshow("source", src);

    // Convert the image to Gray
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    // 2. Filter

    src_gray.copyTo(dst_filtered);

/*    cv::GaussianBlur(src, dst_filtered, cv::Size(3,3), 0, 0);
    cv::imshow("Filtered", dst_filtered);*/

/*    cv::medianBlur(src, dst_filtered, 3);
    namedWindow("Median", WINDOW_AUTOSIZE);
    imshow("Median", dst_filtered);*/

/*    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    cv::Laplacian(src, dst, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT);
    src.convertTo(src, CV_16S);
    dst_filtered = src - dst;
    dst_filtered.convertTo(dst_filtered, CV_8U);
    cv::imshow("Laplacian", dst_filtered);*/

    // 3. Ploting Histogram
    // plotHist(dst_filtered,"Histogram", 500, 500);

    // 4. Thresholding and Morphology

    int threshold_value = 140;
    int max_BINARY_value = 255;
    int threshold_type = 8;

    threshold(dst_filtered, dst_threshold, threshold_value, max_BINARY_value, threshold_type);
    erode(dst_threshold, dst_morph, element);
    //morphologyEx(dst_threshold, dst_morph, MORPH_OPEN, element);

    // 5. Draw Contours on the original image
    contour(src, dst_morph);


    // imshow("dst", dst_morph);
    waitKey(0);

}

void plotHist(Mat src, string plotname, int width, int height) {
    /// Compute the histograms
    Mat hist;
    /// Establish the number of bins (for uchar Mat type)
    int histSize = 256;
    /// Set the ranges (for uchar Mat type)
    float range[] = { 0, 256 };

    const float* histRange = { range };
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    double min_val, max_val;
    cv::minMaxLoc(hist, &min_val, &max_val);
    Mat hist_normed = hist * height / max_val;
    float bin_w = (float)width / histSize;
    Mat histImage(height, width, CV_8UC1, Scalar(255));
    for (int i = 0; i < histSize - 1; i++) {
        line(histImage,
             Point((int)(bin_w * i), height - cvRound(hist_normed.at<float>(i, 0))),
             Point((int)(bin_w * (i + 1)), height - cvRound(hist_normed.at<float>(i + 1, 0))),
             Scalar(0), 2, 8, 0);
    }

    imshow(plotname, histImage);
}

void contour(Mat& src, Mat dst){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    /// Find contours
    findContours(dst, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    /// Convert the source image to color if it is not already
    for(int i = 0; i < contours.size(); i++)
    {
        if(contourArea(contours[i]) < 300){
            continue;
        }
        else{
            printf(" * Contour[%d] -  Area OpenCV: %.2f - Length: %.2f \n", i, contourArea(contours[i]), arcLength( contours[i], true ) );

            Scalar color = Scalar(rand() & 255, rand() & 255, rand() & 255); // Random color
            Rect boundRect = boundingRect(contours[i]);
            rectangle(src, boundRect.tl(), boundRect.br(), color, 2);
        }
    }
    namedWindow("Contours on Original", WINDOW_AUTOSIZE);

    imshow("Contours on Original", src);
}


