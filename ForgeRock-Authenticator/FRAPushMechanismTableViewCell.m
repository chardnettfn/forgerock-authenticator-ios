/*
 * The contents of this file are subject to the terms of the Common Development and
 * Distribution License (the License). You may not use this file except in compliance with the
 * License.
 *
 * You can obtain a copy of the License at legal/CDDLv1.0.txt. See the License for the
 * specific language governing permission and limitations under the License.
 *
 * When distributing Covered Software, include this CDDL Header Notice in each file and include
 * the License file at legal/CDDLv1.0.txt. If applicable, add the following below the CDDL
 * Header, with the fields enclosed by brackets [] replaced by your own identifying
 * information: "Portions copyright [year] [name of copyright owner]".
 *
 * Copyright 2016 ForgeRock AS.
 */

#import "FRAPushMechanismTableViewCell.h"

@implementation FRAPushMechanismTableViewCell

#pragma mark -
#pragma mark UIView

- (void)awakeFromNib {
    [super awakeFromNib];
    self.notificationsBadge.verticalAlignment = M13BadgeViewVerticalAlignmentNone;
    self.notificationsBadge.horizontalAlignment = M13BadgeViewHorizontalAlignmentNone;
    self.notificationsBadge.hidesWhenZero = YES;
}

#pragma mark -
#pragma mark UITableViewCell

- (void)setEditing:(BOOL)editing animated:(BOOL)animated {
    [super setEditing:editing animated:animated];
    self.delegate.editing = editing;
}

@end
