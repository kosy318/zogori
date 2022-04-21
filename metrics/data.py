import os
import pandas as pd
import openpyxl
from cpp_complexity import cal_complexity
folderList = [chr(i) for i in range(65,77)]
print(folderList)

fileList = {}
path = "./SORTED_BY_PROBLEMS/"
for i in range(len(folderList)):
    tempFileList = os.listdir(path+folderList[i]+"/")
    cppList = [file for file in tempFileList if (file.endswith(".cpp") or file.endswith(".c"))]
    fileList[folderList[i]] = cppList

writer=pd.ExcelWriter('output.xlsx', engine='openpyxl')

for i in folderList:
    temp_dic = {'filename':[],'distinct_func':[], 'number_func':[],'distinct_var':[],'number_var':[],
                'depth':[],'loc':[],'elegance':[]}
    for j in fileList[i]:
        distinct_func, number_func, distinct_var, number_var, depth, loc, elegance = (cal_complexity(path+i+"/"+ j))
        temp_dic['filename'].append(j)
        temp_dic['distinct_func'].append(len(distinct_func))
        temp_dic['number_func'].append(number_func)
        temp_dic['distinct_var'].append(len(distinct_var))
        temp_dic['number_var'].append(number_var)
        temp_dic['depth'].append(depth)
        temp_dic['loc'].append(loc)
        temp_dic['elegance'].append(elegance)
    df = pd.DataFrame(temp_dic)
    df.to_excel(writer, sheet_name=i)
writer.save()

