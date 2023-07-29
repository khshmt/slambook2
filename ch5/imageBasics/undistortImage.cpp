//STL
#include <string>
#include <filesystem>
//OPENCV
#include <opencv2/opencv.hpp>


std::filesystem::path image_file = "C:/Data/dev/slambook2/ch5/imageBasics/distorted.png"; 

int main(int argc, char *argv[]) {

  constexpr auto k1 = -0.28340811, k2 = 0.07395907, p1 = 0.00019359, p2 = 1.76187114e-05;
  constexpr auto fx = 458.654, fy = 457.296, cx = 367.215, cy = 248.375;

  cv::Mat image = cv::imread(image_file.string(), 0);   // flag=0，CV_8UC1
  cv::Mat image_undistort = cv::Mat(std::move(image.rows), std::move(image.cols), CV_8UC1);
  auto t1 = std::chrono::steady_clock::now();
  for (int v = 0; v < image.rows; v++) {
    for (int u = 0; u < image.cols; u++) {
      auto x = (u - cx) / fx, y = (v - cy) / fy; //return back from sensor palne to image plane then to normalized plane
      auto r = sqrt(x * x + y * y);
      auto x_distorted = x * (1 + k1 * r * r + k2 * r * r * r * r) + 2 * p1 * x * y + p2 * (r * r + 2 * x * x);
      auto y_distorted = y * (1 + k1 * r * r + k2 * r * r * r * r) + p1 * (r * r + 2 * y * y) + 2 * p2 * x * y;
      auto u_distorted = fx * x_distorted + cx;
      auto v_distorted = fy * y_distorted + cy;

      if (u_distorted >= 0 && v_distorted >= 0 && u_distorted < image.cols && v_distorted < image.rows) {
        image_undistort.at<uchar>(v, u) = image.at<uchar>(static_cast<int>(v_distorted), static_cast<int>(u_distorted));
      } else {
        image_undistort.at<uchar>(v, u) = 0;
      }
    }
  }
  auto t2 = std::chrono::steady_clock::now();
  std::cout << "Time taken to distor images: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms\n";

  cv::imshow("distorted", image);
  cv::imshow("undistorted", image_undistort);
  cv::waitKey();
  return 0;
}
