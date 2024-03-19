/*#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Load the Image in gray-scale
    Mat src = imread("../Image/HGU_logo.jpg", IMREAD_GRAYSCALE);

    if (src.empty())
    {
        cout << "Error: Couldn't open the Image." << endl;
        return -1;
    }

    // Calculate the sum of pixel intensities using 'at' function
    double sumIntensity = 0.0;
    for (int i = 0; i < src.rows; i++){
        for (int j = 0; j < src.cols; j++){
            sumIntensity += src.at<uchar>(i,j);
        }
    }

    // Calculate the total number of pixels in the Image
    int pixelCount =  src.rows * src.cols;

    // Calculate the average intensity of the Image
    double avgIntensity = sumIntensity / pixelCount;

            // Print the results
            cout << "Sum of intensity: " << sumIntensity << endl;
    cout << "Number of pixels: " << pixelCount << endl;
    cout << "Average intensity: " << avgIntensity << endl;

    // Display the gray-scale Image
    imshow("src", src);
    waitKey(0);

    return 0;
}*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Load the image
    Mat src = imread("../Image/HGU_logo.jpg", 0);

    if (src.empty())
    {
        cout << "Error: Couldn't open the image." << endl;
        return -1;
    }

    // Initialize dst with the same size as srcGray
    Mat dst = Mat::zeros(src.size(), src.type());

    // Invert the colors by accessing each pixel
//    for(int i=0; i<src.rows; i++){
//        for(int j=0; j<src.cols; j++){
//            dst.at<uchar>(i,j) = 255 - src.at<uchar>(i, j);
//        }
//    }
    dst = 255 - src;

    // Display the original and inverted images
    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);

    return 0;
}