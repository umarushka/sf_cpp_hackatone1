#ifndef _RECEIVER_H
#define _RECEIVER_H


class Receiver {
  public:
    Receiver();

    virtual ~Receiver();

    Receiver(Receiver & source);

    Receiver(const Receiver & source);

    Receiver & operator=(Receiver & source);

    Receiver & operator=(const Receiver & source);

    friend  ostream & operator<<(ostream & os, const Receiver & x);

};
#endif
