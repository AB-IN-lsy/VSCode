/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-25 20:05:38
 * @FilePath: \Acwing\TMP\TMP.CPP
 * @LastEditTime: 2023-07-17 08:38:47
 */
#include <iostream>
#include <string>

std::string convertToTitle(int n)
{
    std::string result = "";

    while (n > 0)
    {
        // 将 n 转换为 0-25 的数，表示 A-Z
        int digit = (n - 1) % 26;

        // 将数字转换为对应的大写字母
        char c = digit + 'A';

        // 将字符插入到结果字符串的开头
        result = c + result;

        // 更新 n，去除已经处理的部分
        n = (n - 1) / 26;
    }

    return result;
}

int main()
{
    int n;
    std::cin >> n;

    std::string excelColumn = convertToTitle(n);
    std::cout << excelColumn << std::endl;

    return 0;
}
