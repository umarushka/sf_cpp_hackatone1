#ifndef _ADAPTERINTERACTION_H
#define _ADAPTERINTERACTION_H


class AdapterInterAction {
  public:
    AdapterInterAction();

    virtual ~AdapterInterAction();

    AdapterInterAction(AdapterInterAction & source);

    AdapterInterAction(const AdapterInterAction & source);

    AdapterInterAction & operator=(AdapterInterAction & source);

    AdapterInterAction & operator=(const AdapterInterAction & source);

    friend  ostream & operator<<(ostream & os, const AdapterInterAction & x);

};
#endif
