import csv
import cs50
from sys import argv

interface = argv[1]
# open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

ddd = db.execute("SELECT first,middle,last,house,year FROM houses WHERE house=? ORDER BY last", interface)
for dd in ddd:
    for d in dd.values():
        if d == None:
            continue
        print(d, end=' ')
    print()

