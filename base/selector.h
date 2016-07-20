/*
 * selector.h
 *
 *  Created on: Dec 16, 2013
 *      Author: fan
 */

#ifndef RAFT_BASE_SELECTOR_H_
#define RAFT_BASE_SELECTOR_H_

#include <poll.h>
#include <vector>
#include <map>
#include <boost/noncopyable.hpp>
#include <raft/base/selectable.h>

namespace raft {

typedef std::vector<Selectable*> SelectableList;

// not thread safe
class Selector: boost::noncopyable {
public:
    Selector();
    void Register(Selectable* s);
    int Select(SelectableList* l, int timeout);
    int Poll(Selectable* s, int timeout);
    void Reset();

private:
    typedef std::vector<struct pollfd> PollfdList;
    typedef std::map<int, Selectable*> SelectableMap;
    PollfdList pollfdList_;
    SelectableMap selectableMap_;
};

} /* namespace raft */
#endif /* RAFT_SELECTOR_H_ */
