#ifndef USERADMIN_H
#define USERADMIN_H

#include "iuser.h"

class UserAdmin : public IUser
{
public:
    explicit UserAdmin(QObject *parent = nullptr);

};

#endif // USERADMIN_H
