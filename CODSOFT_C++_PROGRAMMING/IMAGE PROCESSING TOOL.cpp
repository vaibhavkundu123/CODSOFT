#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load image
    Mat image = imread("image.jpg");
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Display image
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);

    // Image filters
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    namedWindow("Grayscale Image", WINDOW_AUTOSIZE);
    imshow("Grayscale Image", grayImage);

    Mat blurImage;
    GaussianBlur(image, blurImage, Size(15, 15), 0);
    namedWindow("Blur Image", WINDOW_AUTOSIZE);
    imshow("Blur Image", blurImage);

    Mat sharpenImage;
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, sharpenImage, -1, kernel);
    namedWindow("Sharpen Image", WINDOW_AUTOSIZE);
    imshow("Sharpen Image", sharpenImage);

    // Color adjustment
    Mat brightImage = image + Scalar(50, 50, 50);
    namedWindow("Bright Image", WINDOW_AUTOSIZE);
    imshow("Bright Image", brightImage);

    Mat darkImage = image - Scalar(50, 50, 50);
    namedWindow("Dark Image", WINDOW_AUTOSIZE);
    imshow("Dark Image", darkImage);

    // Crop and resize
    Rect roi(100, 100, 200, 200);
    Mat croppedImage = image(roi);
    namedWindow("Cropped Image", WINDOW_AUTOSIZE);
    imshow("Cropped Image", croppedImage);

    Mat resizedImage;
    resize(image, resizedImage, Size(), 0.5, 0.5);
    namedWindow("Resized Image", WINDOW_AUTOSIZE);
    imshow("Resized Image", resizedImage);

    // Save processed image
    imwrite("processed_image.jpg", resizedImage);

    waitKey(0);
    return 0;
}
