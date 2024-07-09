/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:06:40 by bat               #+#    #+#             */
/*   Updated: 2024/07/09 14:50:52 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1,
    const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

std::string Replace::readInputFile() const {
    std::ifstream   ifs(_filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: Could not open input file" << _filename
            << std::endl;
        return "";
    }
    // my double iterator input ifs and output stream to create a string (content)
    // by copying all characterz betwieen both iterators
    std::string content((std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>());
    ifs.close();
    return content;
}

// Write the replaced content to the output file
void Replace::writeOutputFile(const std::string& content) const {
    std::string outputFilename = _filename + ".replace";
    std::ofstream ofs(outputFilename.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open output file " << outputFilename
            << "'" << std::endl;
        return;
    }

    ofs << content;
    ofs.close();
}

// Replace all occurrences of _s1 with _s2 in the content
std::string Replace::replaceOccurences(const std::string& content) const {
    std::string result;
    size_t pos = 0;
    size_t prevPos = 0;
    size_t s1Len = _s1.length();

    while ((pos = content.find(_s1, prevPos)) != std::string::npos) {
        result.append(content, prevPos, pos - prevPos);
        result.append(_s2);
        prevPos = pos + s1Len;
    }
    result.append(content, prevPos, std::string::npos);
    return result;
}

// Launch the replacement process
void Replace::launchReplacement() const {
    std::string content = readInputFile();
    if (content.empty()) {
        std::cerr << "Error: Failed to read input file or file is empty."
            << std::endl;
        return;
    }
    std::string replacedContent = replaceOccurences(content);
    writeOutputFile(replacedContent);
}