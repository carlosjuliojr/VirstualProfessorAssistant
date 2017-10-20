#ifndef GENERATORDB_H
#define GENERATORDB_H
#include <QApplication>
#include<QDateTime>
#include<QDebug>
#include <iostream>
#include<fstream>
#include <fstream>
#include <cstring>
#include<string>
#include"../../../include/databasestructs.h"


class GeneratorDB
{
   public:


      GeneratorDB();
      ~GeneratorDB();
      /**
       * @brief generatorAll
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorAll(string dir_file_person_txt_in, string dir_file_person_binary_out,
                        string dir_file_account_txt_in, string dir_file_account_binary_out,
                        string dir_file_cards_txt_in, string dir_file_cards_binary_out,
                        string dir_file_transaction_txt_in, string dir_file_transaction_binary_out,
                        string dir_file_relationsc_txt_in, string dir_file_relationsc_binary_out,
                        string dir_file_evaluation_txt_in, string dir_file_evaluation_binary_out
                        );
      /**
       * @brief generatorPerson
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorPerson(string dir_file_txt_in, string dir_file_binary_out);
      /**
       * @brief generatorAccount
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorCourse(string dir_file_txt_in, string dir_file_binary_out);
      /**
       * @brief generatorCards
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorCalification(string dir_file_txt_in, string dir_file_binary_out);
      /**
       * @brief generatorBankTransactions
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorAssistance(string dir_file_txt_in, string dir_file_binary_out);

      /**
       * @brief generatorRelationSC
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorRelationSC(string dir_file_txt_in, string dir_file_binary_out);
      /**
       * @brief generatorEvaluation
       * @param dir_file_txt_in
       * @param dir_file_binary_out
       */
      void generatorEvaluation(string dir_file_txt_in, string dir_file_binary_out);

};

#endif // GENERATORDB_H
