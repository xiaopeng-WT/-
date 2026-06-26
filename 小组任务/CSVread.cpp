#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
	std::vector<std::vector<std::string>> data;//储存CSV表格
	std::ifstream file(filename);//以文件流形式来打开CSV文件，括号中的filename为你需要打开的文件路径
	if (!file.is_open()) {
		throw std::runtime_error("打开文件失败:" + filename);
	}//判断文件是否可打开，并返回未打开的文件名
	std::string line;
	while(std::getline(file, line)) {//读取每一行
		std::vector<std::string>row;//储存当前行
		std::stringstream ss(line);//将字符串转换为字符串流
		std::string cell;//CSV的每个单元格
		while (std::getline(ss, cell, ',')) {//每个单元以逗号分隔
			row.push_back(cell);
		}
		data.push_back(row);//每个单元存入data
	}
	file.close();
	return data;//关闭CSV文件返回data
}
int main() {
	try {
		auto data = readCSV("Station.csv");//读取函数读取data
	std::cout << "上海地铁站点与路线:" << std::endl;
		for (const auto& row : data) {//遍历每行
			for (const auto& cell : row) {//遍历每列
				std::cout << cell << "\t";//以\t分隔每个单元
			}
			std::cout << std::endl;
		}
	}
	catch (const std::exception& e) {//捕捉异常数据
		std::cerr << "异常:" << e.what() << std::endl;
		return 1;
	}
	return 0;
}