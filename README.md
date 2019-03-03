# # PatPractise
Programming Ability Test

## C语言开发环境搭建
1. 从官网下载[Eclipse IDE for C/C++ Developers](https://www.eclipse.org/downloads/packages/release/oxygen/3)，与PAT北京工业大学考点安装的软件相同。各考点开发环境参考[考点联盟](https://www.patest.cn/location)。
2. [VS Code搭建C语言环境](https://blog.csdn.net/qq_28581077/article/details/81380341)。实际配置文件参考```.vscode```文件夹下的```launch.json```和```tasks.json```。
3. DEV-C++，官网下载安装包，默认安装。工具 > 编译选项 > 编译器选项卡中添加```-std=c99```，使编译器支持for循环中定义```int i=0```，[参考](https://www.jianshu.com/p/9b838947adc1)。Code::Blocks界面太丑，Visual Studio2010体积太大且卸载不干净，Eclipse C语言调试的时候，scanf无法中断，所以选择使用DEV-C++作为开发工具并参加PAT考试。

## 代码开发
为了能够适应PAT考试，本项目中的代码都是在Eclipse调试好，然后再保存成“题号.c”的文件。文件“题号.c”可以在VS Code配置的C语言环境中直接运行。

## 常见问题
1. PAT提交之后，编译器警告：
    ```
    a.c: In function ‘main’:
    a.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &n);
    ^~~~~~~~~~~~~~~
    ```
    【解决方案】：判断一下scanf的返回结果。[参考](https://www.e-learn.cn/content/wangluowenzhang/88661)。
    ```
    int main() {
        int t;
        if (scanf("%d", &t) == 1) {
            printf("%d", t);
        } else {
            printf("Failed to read integer.\n");
        }
        return 0;
    }
    ```
    