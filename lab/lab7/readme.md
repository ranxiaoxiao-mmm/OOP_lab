# 设计说明

23307110426 马颢宸

## 一、类图

```mermaid
classDiagram
    class CalendarApp {
        +CalendarApp()
        +void run(int argc, char* argv[])
        -CommandLineParser parser;
    	-CalendarGenerator generator;
    	-CalendarRenderer renderer;
    }

    class CommandLineParser {
        +static Options parse(int argc, char* argv[])
        +struct Options 
    }

    class CalendarGenerator {
        +std::vector<MonthData> generate(const CommandLineParser::Options& options)
        +int getCurrentYear()
        +int getCurrentMonth()
        +struct MonthData 
        -int getFirstDayOfWeek(int year, int month)
        -bool isLeapYear(int year)
        -int getDaysInMonth(int year, int month)
        -std::string getMonthName(int month)
        -std::vector<std::string> generateWeekLines(int year, int month)
    }

    class CalendarRenderer {
        +std::string render(const std::vector<CalendarGenerator::MonthData>& months, int rowMonths)
        -std::string formatWeekLine(const std::vector<std::string>& lines)
        -std::string formatMonthTitle(const std::string& title)
        -std::string getWeekdayHeader()
    }
    
    class MonthData {
    	int year;
        int month;
        std::string title;
        std::vector<std::string> weeks; 
    }
    class Options {
        int year = 0;
        int month = 0;
        int monthsBefore = 0;
        int monthsAfter = 0;
        int rowMonths = 3;
        bool isYearSpecified = false;
        bool isMonthSpecified = false;
    }

    CalendarApp --> CommandLineParser : 创建并调用
    CalendarApp --> CalendarGenerator : 创建并调用
    CalendarApp --> CalendarRenderer : 创建并调用
    CommandLineParser --|> Options : 生成
    CalendarGenerator ..> Options : 调用参数
    CalendarGenerator --|> MonthData : 生成
    CalendarRenderer ..> MonthData : 调用参数
```

## 二、类关系图

```mermaid
classDiagram
    CalendarApp
    CommandLineParser
    CalendarGenerator
    CalendarRenderer
    MonthData
    Options

    CalendarApp --> CommandLineParser : 创建并调用
    CalendarApp --> CalendarGenerator : 创建并调用
    CalendarApp --> CalendarRenderer : 创建并调用
    CommandLineParser --> Options : 生成
    Options --> CalendarGenerator : 调用参数
    CalendarGenerator --> MonthData : 生成
    MonthData --> CalendarRenderer : 调用参数
```

## 三、用例图

![2bffb3847f0fd21c98897793a412aca](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\2bffb3847f0fd21c98897793a412aca.png)



## 四、测试结果与样例

* 测试结果

![d756d6ea8afda02bd8d039a45543db8](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\d756d6ea8afda02bd8d039a45543db8.png)

* 测试样例

![6709a7dfd6f91ed7145dbc1aa28e5ce](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\6709a7dfd6f91ed7145dbc1aa28e5ce.png)

![c6a28a8d1ab50c62cb36e169fc6fc04](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\c6a28a8d1ab50c62cb36e169fc6fc04.png)

![8b01593e91b0810e73a1ac091b924c3](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\8b01593e91b0810e73a1ac091b924c3.png)

![ad7357a8067f59bb993bf1f862d89a6](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\ad7357a8067f59bb993bf1f862d89a6.png)

![85c4c32c0268b3a63600d5444613395](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\85c4c32c0268b3a63600d5444613395.png)



## 五、AI设计批评意见

* ==测试代码编写忽略实际程序行为==

  ![8aacc9741c1f95ec69569973b34eda5](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\8aacc9741c1f95ec69569973b34eda5.png)

  在AI工具编写的实际代码中，出现了测试`cal 2025 5 -A 2`、`cal 2025 5 -B 2`的语句。然而在通过在linux系统中运行这两条命令可知，此为非法命令：

  ![image-20250528135223314](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250528135223314.png)

  除此以外，AI工具在测试代码中还编写了例如`cal 2025 5`、`cal -d 2025 5`等非法命令

  总而言之，在编写相关代码时，AI工具错误理解了程序实际运行时应该解析的正确指令，并试图验证通过错误指令。

* ==忽视了对错误指令的处理与反馈==

  以错误指令`cal 2025 5`为例，在AI工具编写程序中，运行该指令，程序会返回公元5年的日历

  ![image-20250528135657515](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250528135657515.png)

  而在linux系统中运行该指令，程序会返回错误信息

  ![image-20250528135731293](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250528135731293.png)

  可以看出，AI编写工具忽视了对错误指令的处理及信息反馈机制。这也间接导致了上一问题（试图验证通过错误指令）的产生。

* ==忽视了真实历史的日历信息==

  在测试对比`cal 1`指令时发现，linux系统返回的日历与AI工具编写代码返回的日历有明显区别。但运行`cal 2025`指令，二者相同且符合现实信息。

  仔细检查后发现，在**1752年9月**的日历数据中，linux系统缺少了13天的数据信息，即**9/2之后的下一天为9/14**

  ![5d03baeca41786bb0c863d8a5113e69](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\5d03baeca41786bb0c863d8a5113e69.png)

​	而AI工具编写代码中，对应**日期正常递增**

![c7418187867872eaf3b61a26192fa07](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\c7418187867872eaf3b61a26192fa07.png)

​	查询相关信息后得知，这是由于**日历变换的相关历史**导致，即

![image-20250528140618454](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250528140618454.png)

![image-20250528140636697](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250528140636697.png)

​	而AI工具在编写相关指令时，未考虑实际历史的日历变换信息，从而在1752年的数据和真实数据有所出入，进而导致1752年及之前	的所有数据都有变动。

* ==排版调整不美观==

  在最初的AI设计版本中，输出的日历数据在排版上并不美观。

  日期与星期之间无法对齐，且空隙逐列递增；月份title无法正确居中，当一排显示多个月份时，title逐列偏右

  多次询问AI并要求其对齐排版后，仍无法正确输出美观的格式，最终还是依靠手动调整排版。

  总而言之，AI工具虽能写出正确实现程序功能的代码，但对于终端输出的美观与整洁却差强人意。