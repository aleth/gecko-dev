/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
#ifndef nsTableCaptionFrame_h__
#define nsTableCaptionFrame_h__

#include "nscore.h"
#include "nsBodyFrame.h"

/**
 * nsTableCaptionFrame
 * Data structure to maintain information about a single table caption geometry.
 * A caption is simply a body frame with a few extra data fields that cache 
 * minimum and maximum width values.
 *
 * @author  sclark
 */
class nsTableCaptionFrame : public nsBodyFrame
{
public:
  static nsresult NewFrame(nsIFrame**  aInstancePtrResult,
                           nsIContent* aContent,
                           nsIFrame*   aParent);

  virtual void          VerticallyAlignChild(nsIPresContext* aPresContext);

  /** return the min legal width for this caption
    * minWidth is the minWidth of it's content plus any insets
    */
  virtual PRInt32       GetMinWidth();
  
  /** return the max legal width for this caption
    * maxWidth is the maxWidth of it's content when given an infinite space 
    * plus any insets
    */
  virtual PRInt32       GetMaxWidth();

  virtual ~nsTableCaptionFrame();

protected:

  /** protected constructor.
    * @see NewFrame
    */
  nsTableCaptionFrame( nsIContent* aContent, nsIFrame* aParentFrame);

private:
  
  PRInt32 mMinWidth;
  PRInt32 mMaxWidth;

};


#endif
