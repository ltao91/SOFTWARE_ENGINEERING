# SOFTWARE_ENGINEERING
## 1st class 10/7
### HELLO.cpp
print hello.. 

### List.cpp
#### Insert(T key)
Insert the key to the end of list. O(1)

#### Search(T key)
return whether the key exist or not. O(N)

#### Delete(T key)
Delete the key if exited. O(N)

#### Delete_node(Node x)
Delete the node x in list. O(1)

#### print()
print all elements in list.


## 2nd class 10/14
### binary_search.cpp
search the key between ok and ng
if the key existed in vector, return true else return false

### hash.cpp
#### Insert(T key)
Insert the key to the hash. expected O(1)

#### Search(T key)
return whether the key exist or not.  expected O(1)

#### print()
print all elements in hash.


## 3rd class  10/21
### InsertionSort(array v)
sort v,O(N^2)

### QuickSort(array v,int begin,int end)
sort v from begin to end  O(N^2)

### CountSort(array v,array res,int MAX_NUM)
sort v, result in res,set MAX_NUM as max number of v

## 4th class 10/28 && 5th class 11/4 && 6th class 11/11
### B+tree
provide some operations
#### Insert(T k)
insert k to tree

#### Delete(T k)
delete k from tree

#### Search(T k)
return whether k exists in tree

#### Search_Range(T left,T right)
return array containing {key : left<=key<=right}

## 7th class 12/02
### counter_fetch_and_add.cc && counter_pthread_lock.cc && counter_ttas.cc
They work correctly. I implemented my_lock_core

### counter_non_lock.cc
It doesn't take lock so don't work correctly.

## 8th class 12/09
### lock_bptree
#### try_lock(Node* node)
try to get lock of node

#### release_lock(Node* node)
release lock of node

#### get_data(Node* node)
return data of node using lock. we init the data as "void kun"

#### change_data
change data of node using lock

## 9th class 12/16
### main.cpp
Check the throughput with my Bptree both write,read operations.

## 10th class 12/23
### main.cpp
Check the throughput with my Bptree / write ops 
If the key were locked, tx die and retry!
sleep some ms.