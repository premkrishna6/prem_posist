#include <ibits/stdc++.h>
using namespace std;
time_t now = time(0);

int node_number=0;
typedef struct tm {
    int tm_sec;   // seconds of minutes from 0 to 61
    int tm_min;   // minutes of hour from 0 to 59
    int tm_hour;  // hours of day from 0 to 24
    int tm_mday;  // day of month from 1 to 31
    int tm_mon;   // month of year from 0 to 11
    int tm_year;  // year since 1900
    int tm_wday;  // days since sunday
    int tm_yday;  // days since January 1st
    int tm_isdst; // hours of daylight savings time
};
typedef struct node{
    tm *timestamp;
    string data;
    int nodeNumber;
    string nodeId;
    string referenceNodeId;
    vector<node*>childReferenceNodeId;
    string genesisReferenceNodeId;
    hash<string>HashValue;
};

string encrypt(string str)
{
    for(i = 0; (i < 100 && str[i] != '\0'); i++)
    {
        str[i] = str[i] + 3;
    }
    return str;
}

string decrypt(string str)
{
    for(i = 0; (i < 100 && str[i] != '\0'); i++)
    {
        str[i] = str[i] - 3;
    }
    return str;
}

node* createGenesisNode()
{
    string data;
    node *genesisNode;
    cout<<"Enter the owner id, owner name, value for the Genesis node"<<endl;
    cin>>data;
    genesisNode->data=encrypt(data);
    node_number++;
    genesisNode->nodeNumber=node_number;
    genesisNode->referenceNodeId=NULL;
    genesisNode->childReferenceId=NULL;
    genesisNode->genesisReferenceId=genesisNode;
    return genesisNode;
}

void createNode(string par,string child, node* genesisNode)
{
    string data;
    node *Node;
    cout<<"Enter the owner id, owner name, value for the node"<<endl;
    cin>>data;
    Node->timestamp=localtime(&now);
    Node->data=encrypt(data);
    node_number++;
    root->nodeId=root;
    Node->nodeNumber=node_number;
    Node->referenceNodeId=par;
    par->childReferenceId.pushback(Node);
    Node->genesisReferenceId=genesisNode;
}

void longestChain(node *temp)
{
     if (!ptr)
        return 0;
    int maxdepth = 0;
    for (vector<Node*>::iterator it = temp->child.begin();
                              it != temp->child.end(); it++)
        maxdepth = max(maxdepth, depthOfTree(*it));
 
    return maxdepth + 1 ;    
}

void merge(node *n1, node *n2)
{
    n1->childReferenceId.pushback(n2);
    if(findlongestchain(n1)>=findlongestchain(n1))
    {
        for(int i=0;i<n2->referenceNodeId->childReferenceId.size();i++);
        {
            if(n2->referenceNodeId->childReferenceId[i]==n2)
            {
                n2->referenceNodeId->childReferenceId[i];
            }
        }
    }
}

int main()
{
    node *genesisNode=NULL;
    int choice=0;
    do
    {
        cout<<"1. Create the Genesis Node"<<endl;
        cout<<"2. Create set of child nodes of a particular node"<<endl;
        cout<<"3. Create child node that originates from a particular node"<<endl;
        cout<<"4. Find longest chain of Genesis node"<<endl;
        cout<<"5. Find longest chain of any node"<<endl;
        cout<<"6. Merge two nodes"<<endl;
        cout<<"0. Exit"<<endl;
        switch(choice)
        {
            case 1 :
                    if(genesisNode==NULL)
                    {
                        genesisNode = createGenesisNode();
                    }
                    else 
                    {
                        cout<<"Genesis Node already exists"<<endl;
                    }
                    break;
            case 2 :
                    if (genesisNode!=NULL)
                    {
                        int i=0,no_of_nodes;
                        string child,par_en,par_de;
                        cout<<"Enter the owner id, owner name, value to which you want to add a set of nodes"<<endl;
                        cin>>par_en;
                        par_de=decrypt(par_en);
                        cout<<"Enter the number of child nodes to be added to this node"<<endl;
                        cin>>no_of_nodes;
                        while(i<=no_of_nodes)
                        {
                            cout<<"Enter the Owner Id, Owner name, value of the node";
                            cin>>child;
                            createNode(par_de,child,genesisNode);
                        }
                    }
                    else
                    {
                        cout<<"You have to create a Genesis node first."<<<endl;
                        createGenesisNode();
                    }
                    break;
            case 3 :
                    if (genesisNode!=NULL)
                    {
                        int i=0,no_of_nodes;
                        string child,par_en,par_de;
                        cout<<"Enter the owner id, owner name, value to which you want to add a set of nodes"<<endl;
                        cin>>par_en;
                        par_de=decrypt(par_en);
                        cout<<"Enter the Owner Id, Owner name, value of the
                        node";
                        cin>>child;
                        createNode(par_de,child);
                    }
                    else
                    {
                        cout<<"You have to create a Genesis node first."<<<endl;
                        createGenesisNode();
                    }
            case 4 : 
                    longestChain(genesisNode);
                    break;
            case 5 :
                    if(genesisNode!=NULL)
                    {
                        string node;
                        cout<<"Enter owner id, owner name, value of node"<<endl;
                        cin>>node;
                        node=decrypt(node);
                        longestChain(node);
                    }
                    break;
            case 6 :
                    cout<<"enter the owner id, owner name , value of first node"<<endl;
                    string s1;
                    cin>>s1;
                    cout<<"enter the owner id, owner name , value of second node"<<endl;
                    string s2;
                    cin>>s2;
                    node * p1=(find(decrypt(s1)));
                    node * p2=(find(decrypt(s2)));
                    if(p1!=NULL && p2!=NULL)
                    {
                        merge(p1,p2);
                        cout<<"mearged"<<endl;
                    }
                    break;
            case 0 :
                    exit(0);
            default:
                    cout<<"Wrong option"<<endl;
                    break;
        }
    }while(choice!=0);
   return 0;
}
