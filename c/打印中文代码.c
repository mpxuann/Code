#include <stdlib.h>


/* windows 控制台支持显示 utf8 编码的中文字符 */
void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

int main(void)
{
    windows_cmd_support_utf8();

    // 打印输出 utf8 编码的中文字符
}