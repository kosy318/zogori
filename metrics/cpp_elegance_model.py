import os

from cpp_complexity import cal_complexity
import pandas as pd
import numpy as np
from keras.models import load_model


def pred(file_list):
    model = load_model('cpp_elegance_model.h5')

    # file_list = []

    test = {
        "file": [],
        "distinct_func": [],
        "distinct_var": [],
        "number_func": [],
        "number_var": [],
        "depth": [],
        "LOC": [],
        "elegance": [],

        "CCM": [],
        "length": [],
        "estimated_length": [],
        "volume": [],
        "difficulty": [],
        "effort": [],
    }

    for file in file_list:
        res = {}
        if file.split('.')[-1] == 'cpp' or file.split('.')[-1] == 'c':
            res = cal_complexity(file)
            if res['depth'] != 0:
                test['file'].append(file)

                test['distinct_func'].append(len(res['distinct_func']))
                test['distinct_var'].append(len(res['distinct_var']))
                test['number_func'].append(res['number_func'])
                test['number_var'].append(res['number_var'])
                test['depth'].append(res['depth'])
                test['LOC'].append(res['LOC'])
                test['elegance'].append(res['elegance'])

                test['CCM'].append(res['CCM'])
                test['length'].append(res['length'])
                test['estimated_length'].append(res['estimated_length'])
                test['volume'].append(res['volume'])
                test['difficulty'].append(res['difficulty'])
                test['effort'].append(res['effort'])
        else:
            file_list.remove(file)

    col = ['distinct_func', 'distinct_var', 'number_func', 'number_var', 'depth', 'LOC', 'elegance', 'CCM', 'length',
           'estimated_length', 'volume', 'difficulty', 'effort']

    for c in col:
        c_max = max(test[c])
        for i in range(len(test[c])):
            test[c][i] = test[c][i] / c_max

    test_df = pd.DataFrame(test)

    X_test = test_df.drop('file', axis=1)
    y_pred = model.predict(X_test)
    y_pred = np.argmax(y_pred, axis=1)

    for i in range(len(test['file'])):
        if y_pred[i] == 2:
            print(
                f'<tr><td style="background-color: tomato; color: white;">{test["file"][i]}</td><td>{test["elegance"][i]}</td></tr>')
        else:
            print(f'<tr><td>{test["file"][i]}</td><td>{test["elegance"][i]}</td></tr>')
