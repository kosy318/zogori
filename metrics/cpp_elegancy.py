import numpy as np


def cal_elegancy(result):
    elegancy = result['number_var'] + len(result['distinct_var']) + len(result['distinct_var']) / result['number_var']
    elegancy += result['number_func'] + len(result['distinct_func']) + len(result['distinct_func']) / result['number_func']
    elegancy += result['LOC']
    elegancy = 100 * pow(elegancy / 100, np.log(result['depth']))

    return elegancy
