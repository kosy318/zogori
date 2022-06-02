import os
import pandas as pd
import matplotlib.pyplot as plt
import openpyxl
import cpp_complexity as cppcom


folderList = [chr(i) for i in range(65,77)]
path = "./SORTED_BY_PROBLEMS/"
print(folderList)

def make_excel():
    fileList = {}
    for i in range(len(folderList)):
        tempFileList = os.listdir(path+folderList[i]+"/")
        cppList = [file for file in tempFileList if (file.endswith(".cpp") or file.endswith(".c"))]
        fileList[folderList[i]] = cppList
    #
    writer=pd.ExcelWriter('output.xlsx', engine='openpyxl')

    for i in folderList:
        temp_dic = {'filename':[],'distinct_func':[], 'number_func':[],'distinct_var':[],'number_var':[],
                    'depth':[],'loc':[],'elegance':[]}
        for j in fileList[i]:
            print(path+i+"/"+ j)
            result = (cppcom.cal_complexity(path+i+"/"+ j))
            temp_dic['filename'].append(j)
            temp_dic['distinct_func'].append(len(result['distinct_func']))
            temp_dic['number_func'].append(result['number_func'])
            temp_dic['distinct_var'].append(len(result['distinct_var']))
            temp_dic['number_var'].append(result['number_var'])
            temp_dic['depth'].append(result['depth'])
            temp_dic['loc'].append(result['LOC'])
            temp_dic['elegance'].append(result['elegance'])

        df = pd.DataFrame(temp_dic)
        df.to_excel(writer, sheet_name=i,index=False)
    writer.save()

def read_excel(filename):
    list = []
    for i in range(len(folderList)):
        list.append(pd.read_excel(filename,sheet_name=i,engine='openpyxl'))
    return list


def make_distribution(list, num, col):
    plot_max = min(list[num][col])
    x = list[num][col] == plot_max
    print(list[num][x])
    plot_max = max(list[num][col])
    x = list[num][col] == plot_max
    print(list[num][x])

    plotList = [0 for _ in range(plot_max+5)]
    for i in list[num][col]:
        plotList[i] += 1
    plt.plot(plotList)
    plt.show()
