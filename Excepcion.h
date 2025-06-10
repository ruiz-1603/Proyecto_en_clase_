//
// Created by RuizM on 6/9/2025.
//

#ifndef EXCEPCION_H
#define EXCEPCION_H
#include <exception>
#include"Utilities.h"
class Excepcion : public std::exception{
  private:
    string message;
  public:
    explicit Excepcion(const string& message = "Error"){
      this->message = message;
      }
    const char* what() const throw(){
      return message.c_str();
    }

};
#endif //EXCEPCION_H