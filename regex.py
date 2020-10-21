import re

filer = open("regexfile.txt" , "r")
reader = filer.read()

sentence = re.split(',\sfor\s|,\sand\s|,\snor\s|,\sbut\s|,\sor\s|,\syet\s|,\sso\s',  reader)
for i in sentence:
    spacer =  "{}: {}\n"
    counter = sentence.index(i) + 1
    print(spacer.format(counter, i))