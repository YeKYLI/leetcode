
https://github.com/changgyhub/leetcode_101/blob/master/LeetCode%20101%20-%20A%20LeetCode%20Grinding%20Guide%20(C%2B%2B%20Version).pdf


https://github.com/pezy/LeetCode/tree/master


google/coding-competitions-archive: Google Coding Competitions problem archive (github.com)

[https://github.com/doocs/leetcode/tree/main/solution](https://github.com/doocs/leetcode)

相关内容已备份至网盘 以下是处理脚本

```
import os  
import sys

root_directory = '/Users/baiyuxiu/Downloads/leetcode-0.2.0 3/solution/ALL'  
output_file_path = '/Users/baiyuxiu/Desktop/output.txt'  

output = {}
x = 1

for subdir in os.listdir(root_directory):
    if subdir[0] == '.':
         continue
    
    # print(subdir)
    # print(subdir[0: 4])
    # print(root_directory + "/" + subdir)
    cpp_file_path = root_directory + "/" + subdir + "/" + "Solution.cpp"
    sql_file_path = root_directory + "/" + subdir + "/" + "Solution.sql"
    py_file_path = root_directory + "/" + subdir + "/" + "Solution.py" 
    ts_file_path = root_directory + "/" + subdir + "/" + "Solution.ts"

    try:  
        with open(cpp_file_path, 'r', encoding='utf-8') as file:
            con = file.read()  # 读取整个文件内容到字符串  
    except FileNotFoundError:
        try:  
            with open(sql_file_path, 'r', encoding='utf-8') as file:
                con = file.read()  # 读取整个文件内容到字符串  
        except FileNotFoundError:
                try:
                     with open(py_file_path, 'r', encoding='utf-8') as file:
                          con = file.read()
                except FileNotFoundError:
                    try:
                        with open(ts_file_path, 'r', encoding='utf-8') as file:
                          con = file.read()
                    except FileNotFoundError:
                        con = "//TODO"
                        x += 1
                        

    output[int(subdir[0:4])] = (subdir, con)

print("||||||||||||||||||||")

with open(output_file_path, 'w') as file: 
    for key in sorted(output):
        file.write(output[key][0] + "\n")
        file.write(output[key][1])
        file.write("\n\n")

    
# 替换为你的根目录和输出文件路径  
```

