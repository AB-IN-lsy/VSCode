'''
Author: NEFU AB_IN
Date: 2021-08-31 14:55:19
FilePath: \Vscode\Excel&python\lesson6_move.py
LastEditTime: 2021-08-31 14:56:38
'''
from openpyxl import Workbook, load_workbook

wb = load_workbook('new_excel.xlsx')
ws = wb.active

ws.move_range('A3:E4', rows=2, cols=2)
#往右和往下各两格

wb.save('new_excel.xlsx')