import glob
import shutil
import os
rl = glob.glob('*')
for ll in rl:
    qql = ll.split('.')[0].upper()
    print(qql)
    ext = ll.split('.')[1]
    print(ext)
    shutil.move(ll,qql+'.'+ext)