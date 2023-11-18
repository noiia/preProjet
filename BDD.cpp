﻿#include "BDD.h"

using namespace System;
using namespace System::Data::SqlClient;
// Test
BDD::BDD()
{
    try
    {
        // Chaine de connexion
        String^ connectString = "Data Source=127.0.0.1;Initial Catalog=CesiDragons;Persist Security Info=True;User ID=sa;Password=Test$Test1";
        // Objet connection
        connection = gcnew SqlConnection(connectString);
        // Ouverture
        connection->Open();
        System::Diagnostics::Debug::WriteLine("Connexion ok");
        System::Diagnostics::Debug::WriteLine("this->connection est null : " + (this->connection == nullptr ? "true" : "false"));
    }
    catch (Exception^ ex)
    {
        System::Diagnostics::Debug::WriteLine(ex->ToString());
    }
}

BDD::~BDD()
{

}
System::Data::DataSet^ BDD::executeQuery(String^ sql)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlDataAdapter^ da = gcnew SqlDataAdapter(sql, this->connection);
    // Création d'un DataSet
    System::Data::DataSet^ ds = gcnew System::Data::DataSet();
    // Remplissage du DataSet avec le SqlDataAdapter
    da->Fill(ds);

    return ds;
}

int BDD::executeNonQuery(String^ sql)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlCommand^ command = gcnew SqlCommand(sql, this->connection);
    // Execution
    int affectedrows = command->ExecuteNonQuery();
    return affectedrows;
}

int BDD::executeInsert(String^ sql)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlCommand^ command = gcnew SqlCommand(sql + ";SELECT @@ID", this->connection);
    // Execution
    int idGenere = Decimal::ToInt32((Decimal)command->ExecuteScalar());
    return idGenere;
}