<!--
 * @Author: your name
 * @Date: 2021-04-01 10:15:44
 * @LastEditTime: 2021-04-07 08:14:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /my_learn/cpp/cpp_prime_plus.md
-->

# 变量 #
## 变量类型 ##
- ### 整型
  - short 至少16位
  - int 至少与short长
  - long 至少32位且，至少一个int
  - long long 至少一个64位，且至少一个long长
  > limits.h包含了各种类型的限制

  > 初始化方式c++11之后支持{}
  - unsigned类型
  > cout控制符dec, hex, oct
- ### 字符型
  - char
  - unsigned char
  - wchar_t
    > L''表示wchar_t，使用wcin,wcout输入输出
  - char16_t, char32_t
    > 可以表示unicode字符集u'', u'\uxxxx'
- ### bool类型

- ### const 限定符
- ### 浮点数
  - 书写方式, xxx.yyy 或者 xe[+/-]y
  - flout 至少32位
  - double 至少48位，至少和flout一样
  - long double 至少和double一样
- ### 算数运算符
  - 运算符优先级
  - 除法分支
  - 类型转换
    > 初始化或赋值时进行转换
    
    > 表达式包含不同类型

    > 传参时
- ### 复合类型
  - 数组array