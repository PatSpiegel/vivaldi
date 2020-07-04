#include "chrome/browser/ui/views/bookmarks/bookmark_menu_controller_views.h"

#include "browser/menus/vivaldi_bookmark_context_menu.h"
#include "chrome/browser/ui/views/bookmarks/bookmark_menu_delegate.h"
#include "components/bookmarks/browser/bookmark_model.h"
#include "ui/views/controls/menu/menu_runner.h"
#include "ui/views/controls/textfield/textfield.h"

// Allows bookmark menus from a generic view
void BookmarkMenuController::RunMenuAt(const views::View* parent,
                                       const gfx::Rect& rect) {
  menu_delegate_->GetBookmarkModel()->AddObserver(this);
  menu_runner_->RunMenuAt(menu_delegate_->parent(), nullptr, rect,
                          views::MenuAnchorPosition::kTopLeft,
                          ui::MENU_SOURCE_NONE);
}

views::MenuItemView* BookmarkMenuController::GetNextSiblingMenu(bool next,
    bool* has_mnemonics, gfx::Rect* rect) {
  int start_index;
  const bookmarks::BookmarkNode* node = vivaldi::GetNextNode(
      menu_delegate_->GetBookmarkModel(), next, &start_index, rect);
  if (!node || !node->is_folder())
    return nullptr;
  menu_delegate_->SetActiveMenu(node, start_index);
  *has_mnemonics = true;
  return this->menu();
}
