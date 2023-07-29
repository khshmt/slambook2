//STL
#include <iostream>
#include <chrono>
#include <filesystem>
//OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv)
{
	std::filesystem::path img_path{ "C:/Data/dev/slambook/ch5/imageBasics/ubuntu.png" };
	cv::Mat image = cv::imread(img_path.string());

	cv::Mat grey_img(cv::Size(image.rows, image.cols), CV_8UC1);
	cv::cvtColor(image, grey_img, cv::COLOR_BGR2GRAY);
	cv::imshow("image_gray", grey_img);
	cv::waitKey(0);

	if (image.data == nullptr)
	{
		std::cerr << "image from path: " << img_path << " is not existed\n";
		return 0;
	}

	std::cout << "columns: " << image.cols << ", rows: " << image.rows << ", channels: " << image.channels() << '\n';
	cv::imshow("image", image);
	cv::waitKey(0);

	if (image.type() != CV_8UC1 && image.type() != CV_8UC3)
	{
		std::cout << "image type incorrect.\n";
		return 1;
	}

	auto t1 = std::chrono::steady_clock::now();
	for (size_t y = 0; y < image.rows; y++)
	{
		unsigned char* row_ptr = image.ptr<unsigned char>(y);
		for (size_t x = 0; x < image.cols; x++)
		{
			unsigned char* data_ptr = &row_ptr[x * image.channels()];
			for (int c = 0; c != image.channels(); c++)
			{
				unsigned char data = data_ptr[c];
			}
		}
	}
	auto t2 = std::chrono::steady_clock::now();
	auto time_used = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "time consumped to iterate cv::mat: " << time_used.count() << " ms\n";


	cv::Mat image_another = image;
	image_another(cv::Rect(0, 0, 200, 200)).setTo(0);
	cv::imshow("image", image);
	cv::waitKey(0);

	cv::Mat image_clone = image.clone();
	image_clone(cv::Rect(0, 0, 300, 300)).setTo(128);
	cv::imshow("image", image);
	cv::imshow("image_clone", image_clone);
	cv::waitKey(0);

	cv::destroyAllWindows();
	return 0;
}
