



class arraylist{
            int* arr;
            int maxsize;
            int length;
        public:
            arraylist(int s)
            {
                if(s<0)
                    maxsize=10;
                else
                    maxsize=s;
                length=0;
                arr=new int[maxsize];
            }
            bool isEmpty()
            {
                return length == 0;
            }
             bool isFull()
            {
                return length == maxsize;
            }
            int getsize()
            {
                return length;
            }
            void print()
            {
                for(size_t i=0 ; i<length ; i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
            }
            void insertAt(int item, int pos)
            {
                if(isFull())
                    cout<<"Full List\n";
                else if(pos<0 || pos>length)
                    cout<<"out of Range";
                else
                {
                    for(size_t i=length ; i>pos ; i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[pos]=item;
                length++;
                }
            }

               void insertAtEnd(int item)
            {
                if(isFull())
                    cout<<"Full List\n";
                else
                {
                    arr[length]=item;
                   length++;
                }
            }
            int Search(int item)
            {
                if(isEmpty())
                    cout<<"empty List\n";
                else
                {
                    for(size_t i=0 ; i<length ; i++)
                {
                    if(arr[i] == item)
                        return i;
                }
                 return -1;
                }
            }
            void insertNoDuplicate(int item)
            {
                if(isFull())
                    cout<<"Full List\n";
                else if(Search(item) == -1)
                       insertAtEnd(item);

                else
                 cout<<"The Element is there..!\n";
            }
            void updateAt(int item, int pos)
            {

                if(pos<0 || pos>length)
                    cout<<"out of Range\n";
                else
                arr[pos]=item;
            }
            int getelement( int pos)
            {
                if(pos<0 || pos>length)
                    cout<<"out of Range\n";
                else
                 return  arr[pos];
            }
            void RemoveAt( int pos)
            {
                if(isEmpty())
                    cout<<"empty List\n";
                else if(pos<0 || pos>length)
                    cout<<"out of Range\n";
                else
                {
                    for(size_t i=pos ; i<length ; i++)
                {
                    arr[i]=arr[i+1];
                }
                length--;
                }
            }
           ~arraylist()
           {
               delete[]arr;
           }
           void Clear()
           {
               length=0;
           }


};


