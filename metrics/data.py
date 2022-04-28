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
            distinct_func, number_func, distinct_var, number_var, depth, loc, elegance = (cppcom.cal_complexity(path+i+"/"+ j))
            temp_dic['filename'].append(j)
            temp_dic['distinct_func'].append(len(distinct_func))
            temp_dic['number_func'].append(number_func)
            temp_dic['distinct_var'].append(len(distinct_var))
            temp_dic['number_var'].append(number_var)
            temp_dic['depth'].append(depth)
            temp_dic['loc'].append(loc)
            temp_dic['elegance'].append(elegance)
        df = pd.DataFrame(temp_dic)
        df.to_excel(writer, sheet_name=i,index=False)
    writer.save()

df_list = []
def make_df_list(list):
    for i in range(len(folderList)):
        list.append(pd.read_excel('output.xlsx',sheet_name=i,engine='openpyxl'))


def make_distribution(num, col):

    plot_max = max(df_list[num][col])
    plotList = [0 for _ in range(plot_max+5)]
    for i in df_list[num][col]:
        plotList[i] += 1
    plt.plot(plotList)
    plt.show()

make_df_list(df_list)
make_distribution(7,'distinct_var')