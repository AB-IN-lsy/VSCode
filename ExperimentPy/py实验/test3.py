from PIL import Image
from PIL import ImageFilter
im = Image.open('girl.PNG')
om1 = im.filter(ImageFilter.BLUR)# 模糊效果
om2 = im.filter(ImageFilter.CONTOUR)# 轮廓效果
om3 = im.filter(ImageFilter.FIND_EDGES)# 图像的边界效果
om1.save('1.PNG')
om2.save('2.PNG')
om3.save('3.PNG')