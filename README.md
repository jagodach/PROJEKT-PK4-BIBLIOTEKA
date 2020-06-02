# LibrarySystem

Simple library system with console GUI.
Data is stored in .csv files.

## Application flow
- Data loading:
    Application load data from files hardcoded in solution. Maybe paths to files can be passed as run parameters?
    Different object types are stored in different vectors. Vectors have only pointers to objects.
- Data binding
    Objects have references to each other. They only stores id in data files. They use id to find object to bind from other collections.
- Login
- Show GUI - user can select option. Different user types have different GUI. User can only view data and lend items. Admin can do everything.
    - Authors: can be added, viewed and removed,
    - Users: can be added, viewed and removed,
    - Items: can be added, viewed, removed and lend,
    - Lends:
        - can be viewed (user can see only hus lends, admin sees all lends), 
        - can be returned. After returning a lend it goes to history lends. User has to pay money for lend (lend price + 10% lend price for every week late),
        - can be deleted,
        - every item can be lend once (if you have 3 the same books they have to be added as 3 items).
- End program

## Data format
    Data is stored in text files, format is similar to .csv format, but it's not pure .csv. Data format only matter for data loading and saving.
After all, it's just a normal text file.

## Short classes/files overview:
### LibrarySystem.cpp
    File with main(). There is also all GUI logic. It's not really pretty code, but it works and is quite flexible for adding new stuff.
### Library manager
    Class that holds all data and is the only connection with GUI. All logic happens here.
### Helpers
    Class with static methods that do some generic things (like reading/saving file, splitting string).
### Structs
    It contains some simple general types to use in application (SimpleDate and PersonData).
    SimpleDate is simple wrapper to c++ date time features, which aren't simple and are hard to work with.
    PersonData just allows to not attach everywhere name,surname,birthday.
### FileRecord
    Abstract class, which is like interface that allows loading and saving data
### LibraryItem, Book, EBook
    Items in the library. LibraryItem is some basic item, rest is just to show that you can do some inheritance 
    (Book and EBook have only minor differences to present that you understand how it should work. There can be more item classes, but they would be the same and I think it's pointless)
### LendRecord
    It represents the lend. It combines user with item and sets dates and price for lend.