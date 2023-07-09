#pragma once

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

struct NonCopyable {
    NonCopyable() = default;
    NonCopyable& operator=(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};

#endif