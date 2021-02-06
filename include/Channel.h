#ifndef _CHANNEL_H
#define _CHANNEL_H


class Channel {
  public:
    Channel();

    virtual ~Channel();

    Channel(Channel & source);

    Channel(const Channel & source);

    Channel & operator=(Channel & source);

    Channel & operator=(const Channel & source);

    friend  ostream & operator<<(ostream & os, const Channel & x);

};
#endif
