'''
Author: NEFU AB_IN
Date: 2021-08-31 14:49:59
FilePath: \Vscode\Excel&python\lesson5_Insert.py
LastEditTime: 2021-08-31 14:53:41
'''
from openpyxl import Workbook, load_workbook

wb = load_workbook('new_excel.xlsx')
ws = wb.active

ws.insert_rows(3) #在第三行插入一空行
ws.insert_cols(3)

ws.delete_rows(3)
ws.delete_cols(3)


wb.save('new_excel.xlsx')