
import csv
import cs50

open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

db.execute("CREATE TABLE houses (id int, first TEXT, middle TEXT, last TEXT, house TEXT, year NUMERIC, PRIMARY KEY (id))")

with open("characters.csv", "r") as titles:

    reader = csv.DictReader(titles, delimiter=",")
    first = None
    middle = None
    last = None
    house = None
    birth = 0
    id = 1
    for row in reader:
        if len(row['name'].split()) == 3:
            f = row['name'].split()
            db.execute("INSERT INTO houses (id, first, middle, last, house, year) VALUES(?,?,?,?,?,?)", int(id), f[0], f[1], f[2], row["house"], row["birth"])
            id += 1
        else:
            f = row['name'].split()
            db.execute("INSERT INTO houses (id, first, last, house, year) VALUES(?,?,?,?,?)", int(id), f[0], f[1], row["house"], row["birth"])
            id += 1
        # for key,value in row.items():
        #     if key == 'name':
        #         k = value.split()
        #         # print(value)
        #         if len(k) == 3:
        #             first = k[0]
        #             middle = k[1]
        #             last = k[2]
        #         else:
        #             first = k[0]
        #             last = k[1]
        #             middle = None
        #     if key == 'house':
        #         house = value
        #     if key == 'birth':
        #         birth = int(value)
            # db.execute("INSETR INTO houses1 (id, first, middle, last, house, year) VALUES(?,?,?,?,?,?)", int(id), first, middle, last, house, birth)
            # id += 1


















