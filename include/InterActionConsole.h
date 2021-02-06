#ifndef _INTERACTIONCONSOLE_H
#define _INTERACTIONCONSOLE_H


class InterActionConsole {
  public:
    InterActionConsole();

    virtual ~InterActionConsole();

    InterActionConsole(InterActionConsole & source);

    InterActionConsole(const InterActionConsole & source);

    InterActionConsole & operator=(InterActionConsole & source);

    InterActionConsole & operator=(const InterActionConsole & source);

    friend  ostream & operator<<(ostream & os, const InterActionConsole & x);

};
#endif
