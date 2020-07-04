//
// Copyright (c) 2015 Vivaldi Technologies AS. All rights reserved.
//
// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Replacement for RenderViewContextMenuViews in chrome. That class will pull
// the entire chain of render_view_context_menu which we do not want because
// of limited support for accelerators and no support for icons.

#ifndef UI_VIEWS_VIVALDI_CONTEXT_MENU_VIEWS_H_
#define UI_VIEWS_VIVALDI_CONTEXT_MENU_VIEWS_H_

#include <memory>

#include "ui/vivaldi_context_menu.h"

class BookmarkMenuController;

namespace gfx {
class Image;
}

namespace ui {
class SimpleMenuModel;
}

namespace vivaldi {
class ContextMenuPostitionDelegate;
}

namespace views {
class MenuItemView;
class Widget;
}

class ToolkitDelegateViews;

namespace vivaldi {

class VivaldiContextMenuViews : public VivaldiContextMenu {
 public:
  ~VivaldiContextMenuViews() override;
  VivaldiContextMenuViews(content::WebContents* web_contents,
                          ui::SimpleMenuModel* menu_model,
                          const gfx::Rect& rect,
                          ContextMenuPostitionDelegate* delegate);
  void Show() override;
  void SetIcon(const gfx::Image& icon, int id) override;
  void UpdateMenu(ui::SimpleMenuModel* menu_model, int id) override;

 private:
  void RunMenuAt(views::Widget* parent,
                 const gfx::Rect& rect,
                 ui::MenuSourceType type);

  std::unique_ptr<ToolkitDelegateViews> toolkit_delegate_;
  content::WebContents* web_contents_;
  ui::SimpleMenuModel* menu_model_;
  views::MenuItemView* menu_view_;  // owned by toolkit_delegate_
  gfx::Rect rect_;

  DISALLOW_COPY_AND_ASSIGN(VivaldiContextMenuViews);
};

}  // namespace vivialdi

#endif  // UI_VIEWS_VIVALDI_CONTEXT_MENU_VIEWS_H_
