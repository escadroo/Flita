import os
import argparse

time_file = "file_with_time.txt"
table_file = "file_with_table.txt"

# Подготовка аргументов командной строки
parser = argparse.ArgumentParser()
parser.add_argument("--different", required=True, type=int)
parser.add_argument("--identical", required=True, type=int)

# Массив с аргументами командной строки
args = parser.parse_args()

count_of_different_tests = args.different
count_of_identical_tests = args.identical

# Компиляция генерирующего кода
os.system('cc generator.c -o generator')

# Компиляция файла с кодом программы
os.system('cc main.c -o main')

# Создание и удаление содержимого файла, в котором содержится время работы программ
os.system(f'touch {time_file}')
os.system(f'> {time_file}')

number_of_vertex = 10000

for i in range(count_of_different_tests):
    os.system(f'./generator {table_file} {number_of_vertex}')

    for j in range(count_of_identical_tests):
        os.system(f'./main {table_file} {time_file}')

    number_of_vertex += 10000
