#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    /*  read Image  */
    String HGU_logo = "../../../Image/HGU_logo.jpg";
    Mat src = imread(HGU_logo);
    Mat src_gray = imread(HGU_logo, 0);  // read in grayscale

    /*  write Image  */
    String fileName = "writeImage.jpg";
    imwrite(fileName, src);

    /*  display Image  */
    namedWindow("src", WINDOW_AUTOSIZE);
    imshow("src", src);

    namedWindow("src_gray", WINDOW_AUTOSIZE);
    imshow("src_gray", src_gray);

    waitKey(0);
}