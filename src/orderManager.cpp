

#include "..\\include\\orderManager.h"

vector<Order> OrderManager::orderList;
OrderManager odm;

bool OrderManager::ReadFromFile(const string & fileName)
{
    ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << "Can't open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    Order odr;
    if (!fin.eof())
    {
        odr.ReadAOrderFromFile(fin);
    }
    while (!fin.eof())
    {
        orderList.push_back(odr);
        odr.ReadAOrderFromFile(fin);
    }
    fin.close();
    return true;
}
bool OrderManager::WriteToFile(const string & fileName) const
{
    char outFileName[L_tmpnam];
    tmpnam(outFileName);
    ofstream fout(outFileName);
    for (vector<Order>::const_iterator iter =  orderList.begin(); iter != orderList.end(); iter++)
    {
        iter->Write(fout);
    }
    fout.close();
    remove(fileName.c_str());
    rename(outFileName, fileName.c_str());

    return true;
}

bool OrderManager::AddOrder(Order & odr)
{
    orderList.push_back(odr);
    return true;
}

// bool OrderManager::DeleteOrder(const string & id)
// {
//     for (vector<Order>::const_iterator iter = orderList.begin(); iter!=orderList.end(); iter++)
//     {
//         if (iter->getID() == id)
//         {
//             orderList.erase(iter);
//         }
//     }
//     return true;
// }

// bool OrderManager:: ModifyOrder(Order & oldOrder, Order & newOrder)
// {
//     for (vector<Order>::const_iterator iter = orderList.begin(); iter!=orderList.end(); iter++)
//     {
//         if (iter->getID() == oldOrder.getID())
//         {
//             orderList.erase(iter);
//         }
//     }
//     orderList.push_back(newOrder);
//     return true;
// }
void OrderManager::ViewAllOrder() const
{
    for (vector<Order>::const_iterator iter = orderList.begin(); iter!=orderList.end(); iter++)
    {
        iter->Show();
    }
}

void OrderManager::ViewSellerOrder(const string & sellerID) const
{
    for (vector<Order>::const_iterator iter = orderList.begin(); iter!=orderList.end(); iter++)
    {
        if (iter->getSellerID() == sellerID)
        {
            iter->Show();
        }
    }
}

void OrderManager::ViewBuyerOrder(const string & buyerID) const
{
    for (vector<Order>::const_iterator iter = orderList.begin(); iter!=orderList.end(); iter++)
    {
        if (iter->getBuyerID() == buyerID)
        {
            iter->Show();
        }
    }
}