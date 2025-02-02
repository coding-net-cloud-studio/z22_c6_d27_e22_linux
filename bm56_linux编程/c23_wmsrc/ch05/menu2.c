#include <unistd.h>  // 用于进程控制,如sleep()函数
#include <stdio.h>   // 用于输入输出,如printf()函数
#include <stdlib.h>  // 用于动态内存管理,如malloc()和free()函数

// 定义一个字符指针数组,用于存储菜单项
char *menu[] = {
    // 添加新记录的选项
    "a - add new record",
    // 删除记录的选项
    "d - delete record",
    // 退出程序的选项
    "q - quit",
    // 数组结束标志
    NULL,
};

/**
 * @brief 显示欢迎信息和选项列表,并获取用户的选择
 *
 * @param greet 欢迎信息字符串指针
 * @param choices 选项字符串数组指针
 * @return int 用户选择的选项索引,如果输入无效则返回-1
 */
int getchoice(char *greet, char *choices[]);

// 主函数
int main()
{
    int choice = 0;

    // 检查当前输出是否为终端
    if (!isatty(fileno(stdout)))
    {
        // 如果不是终端,打印错误信息并退出程序
        fprintf(stderr, "您不是在一个终端中!\n");
        exit(1);
    }

    // 循环选择菜单项
    do
    {
        // 获取用户选择的菜单项
        choice = getchoice("请选择一个操作", menu);
        // 打印用户选择的菜单项
        printf("您选择了:%c\n", choice);
    } while (choice != 'q');
    // 退出程序
    exit(0);
}

// 函数getchoice接收两个参数:一个欢迎语和一个字符串数组,用于显示菜单并获取用户的选择.
int getchoice(char *greet, char *choices[])
{
    int    chosen = 0;  // 初始化chosen为0,表示用户尚未做出选择
    int    selected;    // 用于存储用户输入的字符
    char **option;      // 指向字符串数组的指针

    // 循环直到用户做出选择
    do
    {
        printf("Choice: %s\n", greet);  // 打印欢迎语
        option = choices;               // 将option指向choices数组

        // 遍历choices数组并打印每个选项
        // 该循环用于遍历并打印字符串数组中的每个字符串
        // 假设option指向一个以空字符结尾的字符串数组
        while (*option)
        {
            // 打印当前指向的字符串
            printf("%s\n", *option);
            // 移动指针到下一个字符串
            option++;
        }

        selected = getchar();  // 获取用户输入的字符
        option   = choices;    // 重置option指向choices数组
                               // 遍历choices数组,检查用户输入的字符是否与某个选项的首字符匹配

        // 该循环用于遍历选项字符串,检查是否有选中的选项
        while (*option)
        {
            // 如果当前选项的第一个字符与选中的字符匹配
            if (selected == *option[0])
            {
                chosen = 1;  // 如果匹配,设置chosen为1,表示找到了选中的选项
                break;       // 匹配成功后跳出循环
            }
            option++;  // 移动到下一个选项
        }

        // 如果用户未做出正确选择,提示重新选择
        // 如果没有选择正确,打印错误信息并提示重新选择
        if (!chosen)
        {
            printf("Incorrect choice, select again\n");
        }

    } while (!chosen);  // 当chosen不为1时,继续循环
    return selected;  // 返回用户选择的字符
}
