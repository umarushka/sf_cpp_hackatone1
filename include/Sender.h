#ifndef _SENDER_H
#define _SENDER_H


class Sender {
  public:
    Sender();

    virtual ~Sender();

    Sender(Sender & source);

    Sender(const Sender & source);

    Sender & operator=(Sender & source);

    Sender & operator=(const Sender & source);

    friend  ostream & operator<<(ostream & os, const Sender & x);

};
#endif
