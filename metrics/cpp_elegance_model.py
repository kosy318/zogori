import os
from cpp_complexity import cal_complexity
import pandas as pd
import numpy as np
from keras.models import load_model
from sklearn.preprocessing import StandardScaler

# calculate elegance using keras sequential model

def pred(file_list):
    model = load_model('metrics/cpp_elegance_model.h5')

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

    elegance = []

    # make input vector 
    for file in file_list:
        res = {}
        if file.split('.')[-1] == 'cpp' or file.split('.')[-1] == 'c':
            res = cal_complexity(file)
            if res['depth'] != 0:
                test['file'].append('__'.join(file.split('/')[-1].split('__')[1:]))

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

    elegance = test['elegance'].copy()

    # standardization
    scale = StandardScaler()
    for c in col:
        test[c] = scale.fit_transform(pd.DataFrame(test[c])).transpose().tolist()[0]

    test_df = pd.DataFrame(test)

    X_test = test_df.drop(['file', 'elegance'], axis=1)
    y_pred = model.predict(X_test,verbose=0)
    y_pred = np.argmax(y_pred, axis=1)

    # return key-value(dictionary) object to make json easily
    json_object = {"language":"cpp","size":len(test['file']),"file_name":test['file'],"ele_score":[],"elegance":[]}
    for i in range(len(test['file'])):
        json_object["ele_score"].append(str(elegance[i]))
        json_object["elegance"].append(str(y_pred[i]))

    return json_object

