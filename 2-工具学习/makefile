
#test1:test1.cpp
#	g++ test1.cpp -o test1

#all:t1 t2
#t1:test.c
#	gcc test.c -o t1
#
#t2:test.c
#	gcc test.c -o t2

# 通配符的使用
# %统配符

# 从当前目录下找到以.c结尾的文件名称，放到src变量中
src=$(wildcard ./*.c)
# src=a.c b.c

# 将src变量中的数据，后缀名由.c修改为.o将结果赋值给obj变量
obj=$(patsubst %.c, %.o, $(src))
# obj=a.o b.o

main:$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@


.PHONY:clean
clean:
	rm -rf main $(obj)


#
#main:a.o
#	gcc $^ -o $@
#a.o:a.s
#	gcc -c $^ -o $@
#a.s:a.i
#	gcc -S $^ -o $@
#a.i:a.c
#	gcc -E $^ -o $@





