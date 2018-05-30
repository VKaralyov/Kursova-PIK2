#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

//#define NumOfTables 20
typedef struct ReservedTables{
    unsigned int day, month, year, payed, price;
    char name[20];
} res_t;

//extern res_t Data[NumOfTables];

#endif /* INCLUDED_GLOBALS_H */
